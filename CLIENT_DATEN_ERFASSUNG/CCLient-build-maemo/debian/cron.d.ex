#
# Regular cron jobs for the cclient package
#
0 4	* * *	root	[ -x /usr/bin/cclient_maintenance ] && /usr/bin/cclient_maintenance
