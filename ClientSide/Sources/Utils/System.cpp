/*
 * Copyright 2018 Vladimir Balun
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "System.hpp"

int Utils::getCountProcessesors() noexcept
{
    SYSTEM_INFO	sysInfo;
    GetSystemInfo(&sysInfo);
    return sysInfo.dwNumberOfProcessors;
}

bool Utils::is64Windows() noexcept
{
    bool is64Architecture = true;
    if (FALSE == GetSystemWow64DirectoryW(nullptr, 0u))
    {
        const int lastError = GetLastError();
        if (ERROR_CALL_NOT_IMPLEMENTED == lastError)
            is64Architecture = false;
    }
    return is64Architecture;
}

bool Utils::is32Windows() noexcept
{
    return !is64Windows();
}
