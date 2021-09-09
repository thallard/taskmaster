package main

import (
	"bufio"
	"fmt"
	"os"
	"taskmaster/srcs/cli/core"
	"taskmaster/srcs/common"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Fill commands dictionnary
	var commands map[string]core.CommandFunc = core.FillCommandsDictionnary()

	for true {
		fmt.Print("\033[33m-> taskmaster: \033[0m")

		line, err := reader.ReadString('\n')
		common.Check(err)
		core.ParseArguments(line, commands)
		//fmt.Print(line)
	}
	return
}