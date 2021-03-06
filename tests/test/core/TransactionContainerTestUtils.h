/**
*** Copyright (c) 2016-present,
*** Jaguar0625, gimre, BloodyRookie, Tech Bureau, Corp. All rights reserved.
***
*** This file is part of Catapult.
***
*** Catapult is free software: you can redistribute it and/or modify
*** it under the terms of the GNU Lesser General Public License as published by
*** the Free Software Foundation, either version 3 of the License, or
*** (at your option) any later version.
***
*** Catapult is distributed in the hope that it will be useful,
*** but WITHOUT ANY WARRANTY; without even the implied warranty of
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*** GNU Lesser General Public License for more details.
***
*** You should have received a copy of the GNU Lesser General Public License
*** along with Catapult. If not, see <http://www.gnu.org/licenses/>.
**/

#pragma once
#include <type_traits>

namespace catapult { namespace test {

	/// Returns the number of transactions in \a transactions.
	template<typename TContainer>
	size_t CountTransactions(TContainer transactions) {
		size_t count = 0;
		for (auto iter = transactions.begin(); transactions.end() != iter; ++iter)
			++count;

		return count;
	}

	/// Traits for accessing a source via a const reference.
	template<typename TSource>
	struct ConstTraitsT {
		using SourceType = typename std::add_const<TSource>::type;

		/// Gets a const reference to \a source.
		static SourceType& GetAccessor(SourceType& source) {
			return source;
		}
	};

	/// Traits for accessing a source via a non-const reference.
	template<typename TSource>
	struct NonConstTraitsT {
		using SourceType = typename std::remove_const<TSource>::type;

		/// Gets a non-const reference to \a source.
		static SourceType& GetAccessor(SourceType& source) {
			return source;
		}
	};
}}
