package core

import (
	"fmt"
	"strings"
)

type Command struct {
	name string
	commnd CommandFunc
}

type CommandFunc func (args[] string)

// Filter and pre-parse before execute the command
func ParseArguments(line string, commands map[string]CommandFunc) {
	if len(line) == 0 || line[0] == '\n' { return }

	// Separe each arguments in a double string array
	args := strings.Fields(line)
	ExecuteCommand(args, commands)
}

// Execute the commands with it arguments
func ExecuteCommand(args []string, commands map[string]CommandFunc) {
	if commands[args[0]] == nil {
		fmt.Println("command \"" + args[0] + "\" doesn't exist.")
		return
	}
	commands[args[0]](args)
}