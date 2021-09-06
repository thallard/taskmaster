package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"os"
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



func ParseConfigFile(configFile string) {
	// Open config file
	file, err := os.Open(configFile)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	// Read line by line
	scanner := bufio.NewScanner(file)
	for true {
		// Check for a new service and it options
		if CreateNewService(&scanner) == nil {
			break
		}
		fmt.Println("youhouuuu")
	}
}

func main() {
	flag.Parse()
	if len(flag.Args()) == 1 {
		ParseConfigFile(flag.Arg(0))
		fmt.Println("Configuration file done.")
	}
}