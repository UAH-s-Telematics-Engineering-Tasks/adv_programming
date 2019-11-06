#!/bin/bash
# Execute me with $ bash P_6_compare_script.sh
P_6_a/P_6_a.ex > P_6_a_output.txt
P_6_b/P_6_b.ex > P_6_b_output.txt
diff -s P_6_a_output.txt P_6_b_output.txt
