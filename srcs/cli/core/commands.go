package core

import (
	"fmt"
)

// Help command, provide global info and can print specific info about one command
func HelpCommand(args []string) {
	dictionnary := make(map[string]string, 10)
	dictionnary["add"] = "usage"

	// Print global info
	if len(args) == 1 {
		fmt.Println("Available commands :")

		fmt.Println("add    exit      open  reload  restart   start   tail")
		fmt.Println("avail  fg        pid   remove  shutdown  status  update")
		fmt.Println("clear  maintail  quit  reread  signal    stop    version")

		fmt.Println("\nFor further information please type : help <command>")
	} else if len(args) == 2 {
		fmt.Println(dictionnary[args[1]])
	}

}

func VersionCommand(args []string) {
	fmt.Println("version 1.0, latest.")
}