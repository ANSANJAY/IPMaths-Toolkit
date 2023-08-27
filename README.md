# 👩‍💻 IPMaths-Toolkit 🧮
🔧 A collection of C functions dedicated to IP address mathematics and manipulations. Dive deep into bitwise operations, subnetting, and other networking essentials. A hands-on approach to mastering IP calculations for budding system programmers. 💻

This  is all about diving deep into the world of IP addresses. Before we move on, ensure you have a solid understanding of bitwise operations in C, as well as the left and right shift operations. Let's get started!

```sql

+--------------------------------------------------+
|               IP Address Calculator               |
+---------+--------+--------+---------+--------+----+
|  Task1  | Task2  | Task3  | Task4   | Task5  |...|
+---------+--------+--------+---------+--------+----+
| Compute | Compute| Convert| Convert | Compute|...|
|   Mask  |Broadcst| IP2Int | Int2IP  | Network|...|
|   Int   | Address|        |         | ID     |...|
+---------+--------+--------+---------+--------+----+
|  Task6  |                   Task7                   |
+---------+-------------------------------------------+
|   Subn. |       Check IP Subnet Membership          |
|   Hosts |                                           |
+---------+-------------------------------------------+

```

## 🎯 Relevance

- This  will help you harness the power of bitwise manipulation, especially when it comes to networking.

## 📋 Prerequisites

1. Mastery over IP address mathematics from this module.
2. Bitwise operations (AND, OR) and shifts (left, right) in C.
3. Ensure you have a GCC compiler. And it's recommended to run this on Linux. 

# IP Address Calculator :mag_right::bulb:

## 1. Computing the integer representation of a subnet mask :performing_arts:

**Function**: `get_mask_value_in_integer_format(char mask_value)`

- **Logic Breakdown**:
  1. **Initialization** :checkered_flag:: Start with a mask where all bits are set to 1 (`0xFFFFFFFF`). This ensures we have a full 32-bit mask representation.
  2. **Calculate unset bits** :computer:: Subtract the mask value from the maximum possible mask value (32) to determine the number of trailing zeros.
  3. **Loop to unset bits** :repeat:: Iterate through the number of bits to unset, and at each iteration, unset the bit at the current position.

## 2. Computing the broadcast address :satellite:

**Function**: `get_broadcast_address(char *ip_addr, char mask, char *output_buffer)`

- **Logic Breakdown**:
  1. **Convert IP to integer** :arrow_right:: Convert the string format of the IP address to an integer format.
  2. **Fetch integer representation of mask** :performing_arts:: Retrieve the integer representation of the provided mask.
  3. **Compute complement** :arrows_counterclockwise:: Invert the mask's bits to obtain the broadcast address's portion.
  4. **OR operation** :heavy_plus_sign:: OR the integer IP with the mask's complement. This gives the broadcast address.
  5. **Convert back to string** :arrow_right:: Convert the resulting integer to a string format and store it in the output buffer.

## 3. Convert IP from string to integer :scroll::arrow_right::1234:

**Function**: `get_ip_integer_equivalent(char *ip_address)`

- **Logic Breakdown**:
  - Use `inet_pton` function to convert the IP's string format to its integer representation.

## 4. Convert IP from integer to string :1234::arrow_right::scroll:

**Function**: `get_abcd_ip_format(unsigned int ip_address, char *output_buffer)`

- **Logic Breakdown**:
  - Use the `inet_ntop` function to convert the integer format of the IP back to its A.B.C.D string format.

## 5. Compute the network ID :globe_with_meridians:

**Function**: `get_network_id(char *ip_address, char mask, char *output_buffer)`

- **Logic Breakdown**:
  1. **Conversion to integer** :arrow_right:: Convert the IP's string format to its integer representation.
  2. **AND operation** :heavy_plus_sign:: Obtain the network ID by AND-ing the IP with the subnet mask.
  3. **Conversion back to string** :arrow_right:: Convert the resulting integer back to its A.B.C.D string format.

## 6. Calculate the number of possible hosts in a subnet :house:

**Function**: `get_subnet_cardinality(char mask_value)`

- **Logic Breakdown**:
  - Compute host bits using `32 - mask_value`.
  - Use \(2^{\text{host bits}} - 2\) to find valid hosts in the subnet.

## 7. Check IP subnet membership :male_detective:

**Function**: `check_ip_subnet_membership(char *network_id, char mask, char *check_ip)`

- **Logic Breakdown**:
  1. **Convert to integer** :arrow_right:: Convert both the provided network ID and the IP to check into integer formats.
  2. **Compute network ID of the given IP** :globe_with_meridians:: Find the network ID of the IP by AND-ing it with the subnet mask.
  3. **Comparison** :left_right_arrow:: Check if the calculated network ID matches the provided one. 

## 🔗 Resources

Two handy links will guide you:
1. [Useful for IP address format conversions](https://www.silisoftware.com/tools/ipconverter.php) 
2. [For double-checking network IDs, broadcast addresses, and the cardinality of subnets](http://jodies.de/ipcalc)

## 🛠 Compilation & Testing

It's wise to stick to a Linux environment.

🍀 Best of luck  🚀

