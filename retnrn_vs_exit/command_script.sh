#!bin/bash

usage() {                                 # Function: Print a help message.
  echo "Usage: $0 -d [def-name]"
  echo "def-name: USE_EXIT, USE_RETURN"
  exit 1
}
exit_abnormal() {                         # Function: Exit with error.
  usage
}

if [ $# = 0 ]; then
    usage
fi

while getopts ":d:" options; do         # Loop: Get the next option;
                                          # use silent error checking;
                                          # options n and t take arguments.
  case "${options}" in                    # 
    d)                                    # If the option is n,
      gcc -D ${OPTARG} -o return_vs_exit return_vs_exit.c
      ./return_vs_exit
      ;; # equivalent break;
    :)                                    # If expected argument omitted:
      echo "Error: -${OPTARG} requires an argument."
      exit_abnormal                       # Exit abnormally.
      ;;
    *)                                    # If unknown (any other) option:
      exit_abnormal                       # Exit abnormally.
      ;;
  esac
done


exit 0
