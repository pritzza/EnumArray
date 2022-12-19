# "EnumArray"
This is the name I have given this container. The motivation behind its 
creation is my affinity for strict and static typing. Plus that I often find 
myself wanting to be able to map structs to enum class values, so this is 
my solution to that. I've never used Rust before but I think this is atleast 
something similar to a feature of it.

It is basically a map between all the values of an enum class and 
some type. The container is compile time, ordered, contiguous, and immutable,
with O(1) acceces and no insertion or removal operations.

C++17
