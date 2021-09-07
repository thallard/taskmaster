package main

// Create a new service
// By default return nil, otherwise return the new service
//func CreateNewService(scanner **bufio.Scanner) *Service {
//	var service *Service = new(Service)
//
//	for (*scanner).Scan() {
//		if len((*scanner).Text()) == 0 {
//			return nil
//		}
//
//		// Check if the current option's service is finished
//		if (*scanner).Text()[0] == '[' || (*scanner).Text()[0] == '\n' {
//			fmt.Println("Fin du service "  + service.name + ".")
//			return service
//		}
//
//		// Fill each attributes of the new service thanks to the config file
//		config := strings.Fields((*scanner).Text())
//		switch config[0] {
//		case "name":
//			service.name = config[2]
//		case "chmod":
//			service.chmod = config[2]
//		case "numprocs":
//			numprocs, err := strconv.Atoi(config[2])
//			if err != nil {
//				FatalError(err)
//			}
//			service.numprocs = numprocs
//		}
//		fmt.Println(config[0])
//	}
//
//	return service
//}

