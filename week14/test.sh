#/bin/bash
./13-6 50 &
signal_pid = $!

sleep 2
kill -10 signal_pid
kill -3 signal_pid
kill -12 signal_pid
kill -11 signal_pid
kill -38 signal_pid
kill -2 signal_pid
kill -5 signal_pid
kill -4 signal_pid
kill -37 signal_pid
kill -24 signal_pid
kill -33 signal_pid
kill -21 signal_pid
kill -8 signal_pid
kill -7 signal_pid
./tkill -p $signal_pid -s 44
