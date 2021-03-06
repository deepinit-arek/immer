//
// immer - immutable data structures for C++
// Copyright (C) 2016 Juan Pedro Bolivar Puente
//
// This file is part of immer.
//
// immer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// immer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with immer.  If not, see <http://www.gnu.org/licenses/>.
//

#pragma once

#include <cstdlib>

namespace immer {

/*!
 * A heap that uses `std::malloc` and `std::free` to manage memory.
 */
struct malloc_heap
{
    /*!
     * Returns a pointer to a memory region of size `size`, if the
     * allocation was successful, or `nullptr` otherwise.
     */
    template <typename... Tags>
    static void* allocate(std::size_t size, Tags...)
    {
        return std::malloc(size);
    }

    /*!
     * Releases a memory region `data` that was previously returned by
     * `allocate`.  One must not use nor deallocate again a memory
     * region that once it has been deallocated.
     */
    static void deallocate(void* data)
    {
        std::free(data);
    }
};

} // namespace immer
