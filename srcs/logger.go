package main

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

func FatalError(err error) {
	Error.Println(err.Error())
	os.Exit(2)
}

func InitLogger() {
	errors, err := os.OpenFile("error_logs.log", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0666)
	if err != nil {
		FatalError(err)
	}

	commons, err := os.OpenFile("logs.log", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0666)
	if err != nil {
		FatalError(err)
	}

	commons_outputs := io.MultiWriter(commons, os.Stdout)
	errors_outputs := io.MultiWriter(errors, os.Stderr)

	Trace = log.New(commons_outputs, "TRACE: ", log.Ldate|log.Ltime|log.Lmicroseconds)
	Info = log.New(commons_outputs, "INFO: ", log.Ldate|log.Ltime|log.Lmicroseconds)
	Warning = log.New(errors_outputs, "WARNING: ", log.Ldate|log.Ltime|log.Lmicroseconds)
	Error = log.New(errors_outputs, "ERROR: ", log.Ldate|log.Ltime|log.Lmicroseconds)
}
