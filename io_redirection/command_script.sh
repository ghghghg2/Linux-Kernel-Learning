# indicate which interperter to use
#!/bin/bash

echo "start..."
while getopts "a:" option; do

	case "${option}" in
		a) # clear
			if [[ "${OPTARG}" == "clear" ]]; then
				# delete words.txt if existed, -f to suppress error
				echo "clear..."
				rm -f words.txt
				rm -f words2.txt
			elif [[ "${OPTARG}" == "execute" ]]; then
				echo "execute..."
				# create empty text file
				touch words.txt
				# fill it with specified words
				echo "peach" >> words.txt
				echo "pear" >> words.txt
				echo "apple" >> words.txt
				# io redirection experiment starts
				# sort the conotent in words.txt and output to words2.txt
				< words.txt sort > words2.txt
			else
				echo "nothing..."
			fi
			;;
	esac
done

exit 0
           







