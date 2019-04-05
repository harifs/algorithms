echo "size(KBs)      User      Responsiblity"
echo "---------      ----      -------------"
for i in `cat /home/dnn/scr/users.txt | awk '{print $1}'`
do
	dudate=`du -sk /home/$i 2>/dev/null | sort -n`
	name=`grep "$i" /etc/passwd| cut -d":" -f5 | cut -d";" -f1`
	space=`echo $dudate | cut -d" " -f1`
	user=`echo $dudate | cut -d" " -f2`
	user=`basename $user`
	if [ $space -gt 125000 ]; then
		tput smso
	fi
	
	while [ `echo "$space" | wc -c` -lt 16 ]; do
	space="$space "
	done

	while [ `echo "$user" | wc -c` -lt 11 ]; do
	user="$user "
	done

	echo "${space}${user}${name}"
	tput rmso
done
