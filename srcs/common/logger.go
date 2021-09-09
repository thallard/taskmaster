package common

import (
	"io"
	"log"
	"os"
)

var (
	Trace   *log.Logger
	Info    *log.Logger
	Warning *log.Logger
	Error   *log.Logger
)

//Fatal error function
func FatalError(err error) {
	Error.Println(err.Error())
	os.Exit(2)
}

func InitLogger() {
	// Make logs directory
	err := os.MkdirAll("../logs", 0777)
	if err != nil {
		println(err)
	}

	//Open files
	errors, err := os.OpenFile("../logs/error_logs.log", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0777)
	if err != nil {
		println(err.Error())
	}

	//Open files
	commons, err := os.OpenFile("../logs/logs.log", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0777)
	if err != nil {
		println(err.Error())
	}

	//Duplicate output
	commonsOutputs := io.MultiWriter(commons, os.Stdout)
	errorsOutputs := io.MultiWriter(errors, os.Stderr)

	//Bind noutput with date and content
	Trace = log.New(commonsOutputs, "TRACE: ", log.Ldate|log.Ltime|log.Lmicroseconds)
	Info = log.New(commonsOutputs, "INFO: ", log.Ldate|log.Ltime|log.Lmicroseconds)
	Warning = log.New(errorsOutputs, "WARNING: ", log.Ldate|log.Ltime|log.Lmicroseconds)
	Error = log.New(errorsOutputs, "ERROR: ", log.Ldate|log.Ltime|log.Lmicroseconds)
}
