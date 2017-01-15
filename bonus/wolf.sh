#!/bin/bash
maps() { ./wolf3d "$@"; }
case "$1" in
    *campaign*)
	maps lvl*
	;;
    *easy*)
	maps maptest
	;;
    *medium*)
	maps testing
	;;
esac
