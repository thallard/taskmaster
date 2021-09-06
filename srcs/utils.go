package main

import "os"

func FatalError(err error) {
	file, err := os.Open("../logs")
	defer file.Close()
	file.WriteString("taskmaster : FATAL_ERROR -> " + err.Error())

	os.Exit(1)
}