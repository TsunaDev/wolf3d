#!/bin/bash
maps() { ./wolf3d "$@"; }
case "$1" in
    campaign)
	maps maps/campaign/lvl1 maps/campaign/lvl2 maps/campaign/lvl3 maps/campaign/lvl4 maps/campaign/lvl5
	;;
    easy)
	maps maps/easy/*
	;;
    medium)
	maps maps/medium/*
	;;
    hard)
	maps maps/hard/*
	;;
    custom)
	maps maps/custom/*
esac
