package main

import (
	"fmt"
	"os")

func FatalError(err error) {
	CreateFileIfNotExists("../logs")
	file, _ := os.Open("../logs")
	file.WriteString("taskmaster : FATAL_ERROR -> " + err.Error())
	check(file.Close())
	os.Exit(2)
}

// Write a basic action/operation in log file
func Log(message string) {
	CreateFileIfNotExists("../logs")
	date := GetCurrentTime()
	fmt.Println("ici")
	file, err := os.OpenFile("./../logs", os.O_WRONLY, 0644)
	//fmt.Println(err.Error())
	check(err)
	fmt.Println("ici")
	write, _ := file.WriteString(date + " : " + message)
	fmt.Println(write)
	check(err)
	fmt.Println("ici")
	check(file.Close())
}

// Write a warning in log file
func LogWarning(warning string) {
	CreateFileIfNotExists("../logs")


}

// Write an error in log file
func LogError() {
	CreateFileIfNotExists("../logs")
}

// Report a crash in log file and kill the daemon
func LogCrash() {
	CreateFileIfNotExists("../logs")
}


