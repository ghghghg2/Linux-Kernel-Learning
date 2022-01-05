# indicate which interperter to use
#!/bin/bash

usage() {
	echo "USAGE:    command_script -a [clear|execute]"
	echo "clear: clear old file"
	echo "execute: execute the command"
	exit -1
}

# check for no option
if [ $# = 0 ]; then 
	usage
fi

while getopts ":a:" option; do

	case "${option}" in
		a) # clear
			if [[ "${OPTARG}" == "clear" ]]; then
				# delete words.txt if existed, -f to suppress error
				echo "clear..."
				rm -f favorites.txt
			elif [[ "${OPTARG}" == "execute" ]]; then
				echo "execute..."
				# find the top 3 popular color in the colors.txt and output to favorites.txt
				< colors.txt sort | uniq -c | sort -r | head -3 > favorites.txt
			else
				echo "nothing..."
			fi
			;;
		?) #nothing specified
			usage
	esac
done

exit 0
           







