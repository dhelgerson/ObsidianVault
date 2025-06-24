# show last 20 files edited
find / -xdev | xargs -d '\n' stat -c '%y %n' | sort | tail -20
