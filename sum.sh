#!/bin/bash
cat sum_out | grep -i "./jtaylor.filler won" > my_wins && cat sum_out | grep -i "^./resources/players/" > other_wins
vimdiff my_wins other_wins
