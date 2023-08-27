#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <arpa/inet.h>
#include <math.h>

#define IS_BIT_SET(n, pos)  ((n & (1 << (pos))) != 0)  // Check if a specific bit is set
#define TOGGLE_BIT(n, pos)  (n = n ^ (1 << (pos)))     // Toggle a specific bit 
#define COMPLEMENT(num)     (num = num ^ 0xFFFFFFFF)   // Get bitwise complement
#define UNSET_BIT(n, pos)   (n = n & ((1 << pos) ^ 0xFFFFFFFF))  // Unset a specific bit
#define SET_BIT(n, pos)     (n = n | 1 << pos)                   // Set a specific bit

#define PREFIX_LEN  15  
#define MAX_MASK_LEN 32  

static unsigned int get_mask_value_in_integer_format(char mask_value) {
    unsigned int mask = 0xFFFFFFFF; // Initially set all bits
    char n_trail_bits = MAX_MASK_LEN - mask_value;
    int i = 0;

    // Unset the trailing bits based on mask_value
    for(; i < n_trail_bits; i++){
        UNSET_BIT(mask, i);
    }
    return mask;
}

// Computes the broadcast address of an IP network
void get_broadcast_address(char *ip_addr, char mask, char *output_buffer){
    unsigned int ip_addr_integer = 0;
    inet_pton(AF_INET, ip_addr, &ip_addr_integer);
    ip_addr_integer =  htonl(ip_addr_integer);  // Convert from little to big endian

    unsigned int mask_integer_format = get_mask_value_in_integer_format(mask);
    COMPLEMENT(mask_integer_format); // Get complement to obtain host bits

    unsigned int broadcast_addr = ip_addr_integer | mask_integer_format; // OR operation to get broadcast address
    broadcast_addr = htonl(broadcast_addr);  // Convert back to little endian
    inet_ntop(AF_INET, &broadcast_addr, output_buffer, PREFIX_LEN + 1);  // Convert integer IP to dot notation
    output_buffer[PREFIX_LEN] = '\0';
}

// Converts IP address from dot notation to its integer representation
unsigned int get_ip_integer_equivalent(char *ip_address){
    unsigned int ip_addr_integer = 0;
    inet_pton(AF_INET, ip_address, &ip_addr_integer);
    return htonl(ip_addr_integer);
}

// Converts IP address from its integer representation to dot notation
void get_abcd_ip_format(unsigned int ip_address, char *output_buffer){
    inet_ntop(AF_INET, &ip_address, output_buffer, PREFIX_LEN + 1);
    output_buffer[PREFIX_LEN] = '\0';
}

// Computes the network ID of an IP address based on its subnet mask
void get_network_id(char *ip_address, char mask, char *output_buffer){
    unsigned int mask_integer_format = get_mask_value_in_integer_format(mask);
    unsigned int ip_address_integer = 0 ;
    inet_pton(AF_INET, ip_address, &ip_address_integer);

    unsigned int network_id = ip_address_integer & mask_integer_format;  // AND operation to get network ID
    network_id = htonl(network_id);
    inet_ntop(AF_INET, &network_id, output_buffer, PREFIX_LEN + 1);     
}

// Calculates the number of hosts in a subnet based on its mask
unsigned int get_subnet_cardinality(char mask_value){
    return pow(2, MAX_MASK_LEN - mask_value) -2 ;  // Subtract 2 for network and broadcast addresses
}

// Checks if a given IP belongs to a subnet
int check_ip_subnet_membership(char *network_id, char mask, char *check_ip){
    unsigned int check_ip_integer = 0;
    inet_pton(AF_INET, check_ip, &check_ip_integer);

    unsigned int mask_integer = get_mask_value_in_integer_format(mask);
    unsigned int calculated_nw_id = check_ip_integer & mask_integer;  // AND operation to compute its network ID

    unsigned int network_id_integer = 0;
    inet_pton(AF_INET, network_id, &network_id_integer);  

    // Compare if calculated network ID matches the provided network ID
    if(network_id_integer == calculated_nw_id)
        return 0;
    return -1;
}

int
main(int argc, char **argv){

/*Testing get_broadcast_address()*/
{ 
    printf("Testing Q1..\n");   
    char ip_address[PREFIX_LEN + 1],
         output_buffer[PREFIX_LEN + 1];
    memset(ip_address, 0, PREFIX_LEN + 1);
    memcpy(ip_address, "192.168.2.10", strlen("192.168.2.10"));
    ip_address[strlen(ip_address)] = '\0';
    char mask = 24;
    memset(output_buffer, 0 , PREFIX_LEN + 1);
    get_broadcast_address(ip_address, mask, output_buffer);
    printf("broadcast address  = %s\n", output_buffer);
    printf("Testing Q1 Done.\n");   
}

/*Testing get_ip_integer_equivalent()*/
{ 
    printf("Testing Q2..\n");   
    char ip_address[PREFIX_LEN + 1];
    memset(ip_address, 0, PREFIX_LEN + 1);
    memcpy(ip_address, "192.168.2.10", strlen("192.168.2.10"));
    ip_address[strlen(ip_address)] = '\0';
    unsigned int a = get_ip_integer_equivalent(ip_address);
    printf("a = %u\n", a);
    printf("Testing Q2 Done.\n");   
}


/*Testing get_abcd_ip_format()*/
{
    char output_buffer[PREFIX_LEN + 1];
    memset(output_buffer, 0 , PREFIX_LEN + 1);
    unsigned int a = 2058138165; 
    printf("Testing Q3..\n");   
    get_abcd_ip_format(htonl(a), output_buffer);
    printf("IP address in A.B.C.D format = %s\n", output_buffer); 
    printf("Testing Q3 Done.\n");   
}


/*Testing get_network_id()*/
{ 
    printf("Testing Q4..\n");   
    char ip_address[PREFIX_LEN + 1],
         output_buffer[PREFIX_LEN + 1];
    memset(ip_address, 0, PREFIX_LEN + 1);
    memcpy(ip_address, "192.168.2.10", strlen("192.168.2.10"));
    ip_address[strlen(ip_address)] = '\0';
    char mask = 20;
    memset(output_buffer, 0 , PREFIX_LEN + 1);
    get_network_id(ip_address, mask, output_buffer);
    printf("Network Id = %s/%u\n", output_buffer, mask);
    printf("Testing Q4 Done.\n");   
}

/*Testing get_subnet_cardinality() */
{
    printf("Testing Q5..\n");    
    char mask = 24;
    printf("Cardinality = %u\n", get_subnet_cardinality(mask));
    printf("Testing Q5 Done.\n");
}

{
/*Testing check_ip_subnet_membser_ship()*/    
    printf("Testing Q6..\n");
    char network_id[PREFIX_LEN + 1];
    strncpy(network_id, "192.168.1.0", strlen("192.168.1.0"));
    network_id[PREFIX_LEN] = '\0';

    char mask = 24;

    char ip_address[PREFIX_LEN + 1];
    strncpy(ip_address, "192.168.1.10",  strlen("192.168.1.10"));

    int res = check_ip_subnet_membser_ship(network_id, mask, ip_address);
    printf("IP Subnet check Result = %s\n", res == 0 ? "Membership true": "Membership false");
    printf("Testing Q6 Done.\n");
}

    return 0;
} 

