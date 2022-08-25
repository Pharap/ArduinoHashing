# Arduino Hashing

A simple library designed to make it easier to store a hash alongside EEPROM data.

## Supported Hash Algorithms

### Summation

Simple summation of bytes.

#### Characteristics

Quality: Poor
Hash Type: Any Integer
Code Size: Small
Speed: Fast

#### Algorithm

```text
hash = 0

foreach byte in object
	hash = hash + byte

return hash
```

### Knuth Hash

Algorithm provided by Donald Knuth in The Art Of Computer Programming Volume 3, Chapter 6.4.

#### Characteristics

Quality: Decent
Hash Type: 32-bit Unsigned Integer
Code Size: Smallish
Speed: Unknown

#### Algorithm

```text
hash = size(object)

foreach byte in object
	hash = ((hash << 5) ^ (hash >> 27)) + byte

return hash
```

## Usage Examples

### Saving to EEPROM with Hash

#### With Hash Type

##### Fully Qualified

```cpp
// Save object to EEPROM
Hashing::EEPROM::putWithHash<Hashing::KnuthHash>(address, object)
```

##### With Alias

```cpp
// Create alias for desired hashing function
using Hash = Hashing::KnuthHash;

// Save object to EEPROM
Hashing::EEPROM::putWithHash<Hash>(address, object);
```

#### With Function Object

```cpp
// Create a function object
Hashing::KnuthHash hash;

// Save object to EEPROM
Hashing::EEPROM::putWithHash(address, object, hash)
```

### Reading from EEPROM with Hash

##### Fully Qualified

```cpp
// Load object from EEPROM
if(Hashing::EEPROM::getWithHash<Hashing::KnuthHash>(address, object))
{
	// This runs if the hash was valid
}
else
{
	// This runs if the hash was invalid
}
```

```cpp
// Load object from EEPROM
if(!Hashing::EEPROM::getWithHash<Hashing::KnuthHash>(address, object))
{
	// This runs if the hash was invalid
}
```

##### With Alias

```cpp
// Create alias for desired hashing function
using Hash = Hashing::KnuthHash;

// Load object from EEPROM
if(Hashing::EEPROM::getWithHash<Hash>(address, object))
{
	// This runs if the hash was valid
}
else
{
	// This runs if the hash was invalid
}
```

```cpp
// Create alias for desired hashing function
using Hash = Hashing::KnuthHash;

// Load object from EEPROM
if(!Hashing::EEPROM::getWithHash<Hash>(address, object))
{
	// This runs if the hash was invalid
}
```

#### With Function Object

```cpp
// Create a function object
Hashing::KnuthHash hash;

// Load object from EEPROM
if(Hashing::EEPROM::getWithHash(address, object, hash))
{
	// This runs if the hash was valid
}
else
{
	// This runs if the hash was invalid
}
```

```cpp
// Create a function object
Hashing::KnuthHash hash;

// Load object from EEPROM
if(!Hashing::EEPROM::getWithHash(address, object, hash))
{
	// This runs if the hash was invalid
}
```

### Calculating Hashes

#### Static Member Function

##### With Alias

```cpp
// Create alias for desired hashing function
using Hash = Hashing::KnuthHash;

// Compute the hash of an object
auto hash_value = Hash::hash(object);
```

##### Without Alias

```cpp
// Compute the hash of an object
auto hash_value = Hashing::KnuthHash::hash(object);
```

#### Function Object

##### With Alias

```cpp
// Create alias for desired hashing function
using Hash = Hashing::KnuthHash;

// Create a function object
Hash hash;

// Compute the hash of an object
auto hash_value = hash(object);
```

##### Without Alias

```cpp
// Create a function object
Hashing::KnuthHash hash;

// Compute the hash of an object
auto hash_value = hash(object);
```