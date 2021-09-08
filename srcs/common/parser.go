package common

import (
	"bufio"
	"os"
	"regexp"
	"strconv"
	"strings"
)

// Main function for parsing, parse each lines with regex constraints
func ParseConfigFile(configFile string) []*Service {
	var count int = 0
	var services = make([]*Service, GetNumberOfServices(configFile))

	// Open the file
	file, err := os.Open(configFile)
	check(err)

	scanner := bufio.NewScanner(file)
	scanner.Scan()

	// Read line by line
	for true {
		// If scanner find a \n or EOF, quit the loop
		if len(scanner.Text()) == 0 {
			break
		}

		// Search for the [name] pattern to create a new service
		ret, err := regexp.MatchString("^\\[[a-z_-]*\\]$", scanner.Text())
		check(err)

		if ret {
			var service *Service = new(Service)
			for true {
				scanner.Scan()

				if len(scanner.Text()) == 0 {
					break
				}
				// Search for an incorrect option pattern
				ret, err = regexp.MatchString("^\\s*[a-z]+\\s*=\\s*[^\\s]+[\\s]*$", scanner.Text())
				check(err)

				// Quit the loop option if pattern is [name]
				if ret == false {
					break
				}

				// Split by spaces and fill options
				FillServiceOptions(strings.Fields(scanner.Text()), &service)
			}

			// Add the new service
			services[count] = service
			count++
		} else {
			return nil
		}
	}
	//Info.Println("Configuration file done.")
	return services
}

// Return the number of services in the configuration file
func GetNumberOfServices(configFile string) int {
	var number int = 0

	// Open the file
	file, err := os.Open(configFile)
	check(err)

	// Read line by line
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		// Search for the [name] pattern with regex
		ret, err := regexp.MatchString("^\\[[a-z_-]*\\]$", scanner.Text())
		check(err)

		// Increment the number of services if regex match
		if ret {
			number++
		}
	}

	// Close file and handle error
	err = file.Close()
	check(err)
	return number
}

// Fill service's options
func FillServiceOptions(config []string, service **Service) {

	switch config[0] {
	case "name":
		(*service).name = config[2]
	case "chmod":
		(*service).chmod = config[2]
	case "autorestart":
		(*service).autorestart = true
	case "autostart":
		(*service).autostart = true
	case "umask":
		(*service).umask = config[2]
	case "workingdir":
		(*service).workingdir = config[2]
	case "startretries":
		value, err := strconv.Atoi(config[2])
		check(err)
		(*service).startretries = value
	}
}
