#!/bin/bash

#Arquitecture

arquitecture_os=$(uname -a)

#cpu count

physical_processors_count=$(lscpu | grep 'Core(s) per socket' | awk '{print $NF}') 

virtual_processors_count=$(lscpu | grep '^CPU(s):' | awk '{print $NF}')

#Reboot

last_reboot=$(who -b | awk '{print $3, $4}')

#Ram

total_memory=$(free -h | awk '/Mem:/ {if ($2 ~ /Gi/) {sub("Gi", "Gb", $2)} else if ($2 ~ /Mi/) {sub("Mi", "", $2)}; print $2}')

used_memory=$(free -h | awk '/Mem:/ {if ($3 ~ /Gi/) {sub("Gi", "Gb", $3)} else if ($3 ~ /Mi/) {sub("Mi", "", $3)}; print $3}')

memory_total_bytes=$(free --byte | grep 'Mem:' | awk '{print $2}')
memory_used_bytes=$(free --byte | grep 'Mem:' | awk '{print $3}')

memory_percentage=$(( (memory_used_bytes * 100) / memory_total_bytes ))

#Disk Memory

size_total=$(lsblk -d -o NAME,SIZE | grep "sda" | awk '{print $2}')
size_used=$(df | awk '!/tmpfs/ {sum += $3} END {printf "%.0f\n", sum/1024}')

size_total_byte=$(lsblk --byte | grep "sda " | awk '{print $4/1024/1024}')
size_used_byte=$(df | awk '!/tmpfs/ {sum += $3} END {printf "%.0f\n", sum/1024}')

size_percentage=$(( ($size_used_byte * 100) / $size_total_byte ))

#Cpu load

#load_idle=$(top -n 1 -b | grep "Cpu(s)" | awk '{print $8}' | tr ',' '.' | xargs)
#load_current=$(expr "100 - $load_idle" | bc)
idle_value=$(top -n 1 -b | grep "Cpu(s)" | awk '{print $8}' | tr ',' '.' | xargs | awk '{printf "%d", $1 * 10}')

idle_value2=$(top -n 1 -b | grep "Cpu(s)" | awk '{print $7, $8}' | awk '{ gsub(/[^0-9.]/, "", $0); print $0}')

load_value=$((1000 - idle_value))
load_percentage=$(printf "%d.%d" $((load_value / 10)) $((load_value % 10)))

load_value2=$((1000 - idle_value2))
load_percentage2=$(printf "%d.%d" $((load_value2 / 10)) $((load_value2 % 10)))

#LVM use

#lvm_use=$(grep -q "/dev/mapper/" /etc/fstab && echo "yes" || echo "no")
lvm_use=$(lsblk -o TYPE | grep -qw "lvm" && echo "yes" || echo "no")

#TCP connections

#tcp_connections=$(netstat | grep "tcp" | grep "ESTABLISHED" | wc -l)
tcp_connections=$(ss | grep "tcp" | grep "ESTAB" |wc -l)

#Number of users

users_number=$(who -q -H | grep "# users=" | tr '# users=' ' ' | awk '{print $1}')

#IP mac address

address_ip=$(ip -4 addr show | grep -oP 'inet \K[\d.]+' | grep -v '127.0.0.1')
address_mac=$(ip a | grep -oP 'link/ether \K[\d:a-zA-Z]+')

#sudo commands

commands_sudo=$(journalctl _COMM=sudo | grep "COMMAND" | wc -l)

echo ""
echo "  #Architecture: $arquitecture_os" #Display architecture
echo "  #CPU physical : $physical_processors_count" #Display physical processors count
echo "  #vCPU : $virtual_processors_count" #Display virtual processors count
echo "  #Memory Usage: $used_memory/$total_memory ($memory_percentage%)"
echo "  #Disk Usage: $size_used/$size_total ($size_percentage%)"
echo "  #CPU load: $load_percentage% $load_percentage2%"
echo "  #Last boot: $last_reboot"
echo "  #LVM use: $lvm_use"
echo "  #Connections TCP : $tcp_connections ESTABLISHED"
echo "  #User log: $users_number"
echo "  #Network: IP $address_ip ($address_mac)"
echo "  #Sudo : $commands_sudo cmd"

