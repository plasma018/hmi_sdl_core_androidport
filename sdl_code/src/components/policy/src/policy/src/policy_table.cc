/*
 Copyright (c) 2013, Ford Motor Company
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following
 disclaimer in the documentation and/or other materials provided with the
 distribution.

 Neither the name of the Ford Motor Company nor the names of its contributors
 may be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 */
#ifdef MODIFY_FUNCTION_SIGN
#include <global_first.h>
#endif
#include "policy/policy_table.h"
#ifdef EXTENDED_POLICY
#  include "policy/sql_pt_ext_representation.h"
#else  // EXTENDED_POLICY
#  include "policy/sql_pt_representation.h"
#endif  // EXTENDED_POLICY

#include "utils/logger.h"

namespace policy {

CREATE_LOGGERPTR_GLOBAL(logger_, "PolicyTable")

PolicyTable::PolicyTable()
    : pt_data_(
#ifdef EXTENDED_POLICY
               new SQLPTExtRepresentation()
#else  // EXTENDED_POLICY
               new SQLPTRepresentation()
#endif  // EXTENDED_POLICY
               ) {
}

PolicyTable::PolicyTable(utils::SharedPtr<PTRepresentation> pt_data)
    : pt_data_(pt_data) {
}

PolicyTable::~PolicyTable() {
  LOG4CXX_INFO(logger_, "Destroying policy table.");
}

}  // namespace policy
