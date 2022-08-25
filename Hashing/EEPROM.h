#pragma once

//
//  Copyright (C) 2022 Pharap (@Pharap)
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#include <EEPROM.h>

namespace Hashing
{
	struct EEPROM
	{
		//
		// For use with static member functions
		//

		template<typename Hash, typename Type>
		static void putWithHash(int address, Type & object)
		{
			using hash_type = typename Hash::hash_type;

			EEPROMClass::put(address, Hash::hash(object));
			EEPROMClass::put(address + sizeof(hash_type), object);
		}

		template<typename Hash, typename Type>
		static bool getWithHash(int address, Type & object)
		{
			using hash_type = typename Hash::hash_type;

			hash_type storedHash;
			
			EEPROMClass::get(address, storedHash);
			EEPROMClass::get(address + sizeof(storedHash), object);

			return (storedHash == Hash::hash(object));
		}

		//
		// For use with function objects
		//

		template<typename Hash, typename Type>
		static void putWithHash(int address, Type & object, Hash hash)
		{
			using hash_type = decltype(hash(object));

			EEPROMClass::put(address, hash(object));
			EEPROMClass::put(address + sizeof(hash_type), object);
		}

		template<typename Hash, typename Type>
		static bool getWithHash(int address, Type & object, Hash hash)
		{
			using hash_type = decltype(hash(object));

			hash_type storedHash;
			
			EEPROMClass::get(address, storedHash);
			EEPROMClass::get(address + sizeof(storedHash), object);

			return (storedHash == hash(object));
		}
	};
}