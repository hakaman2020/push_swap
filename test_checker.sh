#!/bin/bash
if [ "$2" = "mac" ]
then
	ARGS=$(./randgen -1000 1000 $1);echo $ARGS;./push_swap $ARGS | ./checker_Mac $ARGS	
elif [ "$2" = "linux" ]
then
	ARGS=$(./randgen -1000 1000 $1);echo $ARGS;./push_swap $ARGS | ./checker_linux $ARGS
else	
	ARGS=$(./randgen -1000 1000 $1);echo $ARGS;./push_swap $ARGS | ./checker $ARGS
fi	
