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
    TunnelTCP *tunnel = new TunnelTCP();

    if (tunnel->init())
		fatal("=> TunnelTCP Error Exit");

	tunnel->start();
//	sleep(5);
//	tunnel.restart();
//	sleep(5);
//	tunnel.restart();
//	sleep(5);
//	tunnel.restart();
//	sleep(5);
	std::cout << "[Main]: Check if all is working normaly" << std::endl;


	// ADD WHEN DAEMON WILL WORK
//    skeleton_daemon();
//    while (1)
//    {
//        //TODO: Insert daemon code here.
//        syslog (LOG_NOTICE, "First daemon started.");
//        dprintf(1, "First daemon started.");
//        sleep (1000);
//        break;
//    }
//
//    syslog (LOG_NOTICE, "First daemon terminated.");
//    closelog();
//
	while (1) {

	    return 1;
	} // Infinite loop
	return EXIT_SUCCESS;
}