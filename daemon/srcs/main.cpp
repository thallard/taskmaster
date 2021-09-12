/*
 * daemonize.c
 * This example daemonizes a process, writes a few log messages,
 * sleeps 20 seconds and terminates afterwards.
 */

#include "global.hpp"

/**
 * @brief Fatal error, exit after print error
 *
 * @param err Error constant or string
 */
void fatal(std::string err) {
    std::cerr << err << std::endl;
    exit(1);
}

static void skeleton_daemon()
{
    pid_t pid;

    /* Fork off the parent process */
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* On success: The child process becomes session leader */
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    /* Catch, ignore and handle signals */
    //TODO: Implement a working signal handler */
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    /* Fork off for the second time*/
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* Set new file permissions */
    umask(0);

    /* Change the working directory to the root directory */
    /* or another appropriated directory */
    chdir("/");

    /* Close all open file descriptors */
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
    {
        close (x);
    }

    /* Open the log file */
    openlog ("firstdaemon", LOG_PID, LOG_DAEMON);
}

int main()
{
//    bool loop;
//    int sockfd;
//    sockaddr_in addr;
//    char buffer[BUFFER_SIZE];
//    fd_set rd_set, wr_set, curr_set;
//
//    addr.sin_family = AF_INET; // Adress ip only
//    addr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
//    addr.sin_port = htons(TUNNEL_PORT); // Defined in global.h
//
//    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) // Create socket
//        fatal(ERR_FATAL);
//    if ((bind(sockfd, (sockaddr*)&addr, sizeof(addr))) < 0) // Bind socket to address + port
//        fatal(ERR_FATAL);
//    if ((listen(sockfd, 0)) < 0) // Start communication
//        fatal(ERR_FATAL);
//    std::cout << "Communication open :)" << std::endl;
//
//    loop = true;
//    FD_ZERO(&curr_set);
//    FD_SET(sockfd, &curr_set);
//    bzero(&buffer, BUFFER_SIZE);
//    while (loop) {
//        rd_set = wr_set = curr_set;
//        if (select(FD_SETSIZE, &rd_set, &wr_set, NULL, NULL) < 0)
//            continue;
//        for (int fd = 0; fd < FD_SETSIZE; ++fd) {
//            if (FD_ISSET(fd, &rd_set)) {
//                if (fd == sockfd) {
//                    // New connection
//                    FD_SET(fd, &curr_set);
//                    std::cout << "New connection" << std::endl;
//                } else {
//                    if (recv(fd, buffer, BUFFER_SIZE, 0) <= 0) {
//                        FD_CLR(fd, &curr_set);
//                    } else {
//                        // Treat response
//                        std::cout << "Treat response" << std::endl;
//                    }
//                }
//            }
//        }
//    }

    skeleton_daemon();
    while (1)
    {
        //TODO: Insert daemon code here.
        syslog (LOG_NOTICE, "First daemon started.");
        dprintf(1, "First daemon started.");
        sleep (1000);
        break;
    }

    syslog (LOG_NOTICE, "First daemon terminated.");
    closelog();

    return EXIT_SUCCESS;
}