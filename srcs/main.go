package main

import (
	"flag"
	"fmt"
)



func main() {
	flag.Parse()
	if len(flag.Args()) != 1 { return }

	var services []*Service = ParseConfigFile(flag.Arg(0))
	fmt.Println("Configuration file done.")
	fmt.Println(services[0])
	fmt.Println(services[1])
	fmt.Println(services[2])

}