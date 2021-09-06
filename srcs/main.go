package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"os"
	"strings")

type Service struct {
	name string
	numprocs int
	workingdir string
	exitcodes []int
	umask string
	autostart bool
	autorestart bool
	stdout int
	stderr int
}

// Create a new
func createNewService(scanner **bufio.Scanner) *Service {
	var service *Service = new(Service)

	for (*scanner).Scan() {
		if len((*scanner).Text()) == 0 {
			fmt.Println("ici")
			return nil
		}
		// Check if the current option's service is finished
		if (*scanner).Text()[0] == '[' || (*scanner).Text()[0] == '\n' {
			fmt.Println("Fin du service.")
			service.name = "oui"
			return service
		}
		config := strings.Fields((*scanner).Text())
		fmt.Println(config[0])
	}
	service = nil
	return service
}

func parseConfigFile(configFile string) {
	// Open config file
	file, err := os.Open(configFile)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	// Read line by line
	scanner := bufio.NewScanner(file)
	for true {

		//fmt.Println(scanner.Text())
		// Check for a new service and it options

			if createNewService(&scanner) == nil {
				break
			}


	}
}

func main() {
	flag.Parse()
	if len(flag.Args()) == 1 {
		parseConfigFile(flag.Arg(0))
		fmt.Println("Configuration file done.")
	}
}