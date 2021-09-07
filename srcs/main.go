package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
	"regexp"
)

type Service struct {
	name string
	numprocs int
	workingdir string
	exitcodes []int
	umask string
	chmod string
	autostart bool
	autorestart bool
	stdout int
	stderr int
}

//func ParseConfigFile(configFile string) {
//	// Open config file
//	file, err := os.Open(configFile)
//	if err != nil {
//		log.Fatal(err)
//	}
//	defer file.Close()
//
//	// Read line by line
//	scanner := bufio.NewScanner(file)
//	for true {
//		// Check for a new service and it options
//		if CreateNewService(&scanner) == nil {
//			break
//		}
//		scanner.Scan()
//		if len(scanner.Text()) == 0 {
//			break
//		}
//	}
//}


// Return the number of services in the configuration file
func GetNumberOfServices(configFile string) int {
	var number int = 0

	// Open the file
	file, err := os.Open(configFile)
	if err != nil {
		FatalError(err)
	}

	// Read line by line
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		// Search for the [name] pattern with regex
		ret, err := regexp.MatchString("^\\[[a-z_-]*\\]$", scanner.Text())
		if err != nil {
			FatalError(err)
		}
		if ret {
			number++
		}
	}

	// Close file and handle error
	err = file.Close()
	if err != nil {
		FatalError(err)
	}
	return number
}

func ParseConfigFile(configFile string) []*Service {
	var services = make([]*Service, GetNumberOfServices(configFile))

	var service *Service = new(Service)
	services[0] = service
	return services
}

func main() {
	flag.Parse()
	if len(flag.Args()) == 1 {
		ParseConfigFile(flag.Arg(0))
		fmt.Println("Configuration file done.")
	}
}