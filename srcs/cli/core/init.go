package core

// Create a map with name and pointer function for each one
func FillCommandsDictionnary() map[string]CommandFunc {
	commands := make(map[string]CommandFunc, 21)

	commands["help"] = HelpCommand
	commands["version"] = VersionCommand

	return commands
}