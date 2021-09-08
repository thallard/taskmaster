package common

import (
	"os"
	"strconv"
	"time"
)

type Service struct {
	name         string
	numprocs     int
	workingdir   string
	exitcodes    []int
	startretries int
	starttime    int
	stoptime     int
	stopsignal   string
	umask        string
	chmod        string
	autostart    bool
	autorestart  bool
	stdout       string
	stderr       string
}

func GetCurrentTime() string {
	var date string

	// Get current time
	now := time.Now()

	date = "[" + string(now.Day()) + "-" + string(now.Month()) + "] - "
	date += string(now.Hour()) + ":" + string(now.Minute()) + ":" + string(now.Second()) + ":" + strconv.FormatInt(now.UnixMilli(), 10)
	return date
}

func check(err error) {
	if err != nil {
		FatalError(err)
	}
}

func CreateFileIfNotExists(name string) {
	if _, err := os.Stat(name); err == nil {
		return
	} else if os.IsNotExist(err) {
		os.Create(name)

	} else {

	}
}
