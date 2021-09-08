package main

import (
	"flag"
	"fmt"
)

func main() {
	InitLogger()

	flag.Parse()
	if len(flag.Args()) != 1 {
		Info.Println("Usage: taskmaster <config_path>")
		return
	}

	// Log exemple:
	// Trace.Println("I have something standard to say")
	// Info.Println("Special Information")
	// Warning.Println("There is something you need to know about")
	// Error.Println("Something has failed")

	var services []*Service = ParseConfigFile(flag.Arg(0))
	fmt.Println("Configuration file done.")
	fmt.Println(services[0])
	fmt.Println(services[1])
	fmt.Println(services[2])

}
