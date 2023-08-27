# 👩‍💻 IPMaths-Toolkit 🧮
🔧 A collection of C functions dedicated to IP address mathematics and manipulations. Dive deep into bitwise operations, subnetting, and other networking essentials. A hands-on approach to mastering IP calculations for budding system programmers. 💻

This  is all about diving deep into the world of IP addresses. Before we move on, ensure you have a solid understanding of bitwise operations in C, as well as the left and right shift operations. Let's get started!

## 🎯 Relevance

- This  will help you harness the power of bitwise manipulation, especially when it comes to networking.
- For those eyeing system programming jobs, mastering bitwise operations in C is non-negotiable. Interviews will likely touch on this area, so be prepared!

## 📋 Prerequisites

1. Mastery over IP address mathematics from this module.
2. Bitwise operations (AND, OR) and shifts (left, right) in C shouldn't be new to you.
3. Ensure you have a GCC compiler. And it's recommended to run this on Linux. 

## 📜 Tasks

### 1. 📡 `get_broadcast_address`

Craft a function that pinpoints the broadcast address given an IP and its mask value.

**Input:** 
- IP address (as string)
- Mask value (as integer)
  
**Output:** 
- Broadcast address (returns a string)

### 2. 🔢 `get_IP_integral_equivalent`

Transform an IP address into its integral equivalent with this function.

**Input:** 
- IP address (as string)

**Output:** 
- Integer avatar of the IP address

### 3. 🧩 `get_ABCD_IP_format`

Return the traditional A.B.C.D format of an IP address starting from its integer form.

**Input:** 
- IP address (as an unsigned integer)

**Output:** 
- IP address in the A.B.C.D format

### 4. 🆔 `get_network_ID`

For a specific IP address and its mask value, get the network ID.

**Input:** 
- IP address (as string)
- Mask value (as integer)

**Output:** 
- Network ID 

### 5. 🌐 `get_subnet_cardinality`

Compute the total number of assignable IP addresses, aka the cardinality, using the mask value.

**Input:** 
- Mask value (as integer)

**Output:** 
- Max IP addresses one can assign (as integer)

### 6. ✅ `check_IP_membership`

Check if a given IP address lies within a certain subnet.

**Input:** 
- Network ID (as string)
- Mask value (as integer)
- An IP address to test (as string)

**Output:** 
- Returns 0 if the IP address resides in the subnet
- -1 if it doesn't

## 🔗 Resources

Two handy links will guide you:
1. [Link 1](https://www.silisoftware.com/tools/ipconverter.php): Useful for IP address format conversions.
2. [Link 2](http://jodies.de/ipcalc): For double-checking network IDs, broadcast addresses, and the cardinality of subnets.

## 🛠 Compilation & Testing

It's wise to stick to a Linux environment.

🍀 Best of luck  🚀

