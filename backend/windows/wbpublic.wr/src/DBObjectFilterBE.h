/*
 * Copyright (c) 2009, 2018, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0,
 * as published by the Free Software Foundation.
 *
 * This program is designed to work with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms, as
 * designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an additional
 * permission to link the program and your derivative works with the
 * separately licensed software that they have either included with
 * the program or referenced in the documentation.
 * This program is distributed in the hope that it will be useful,  but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 * the GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA 
 */

#ifndef __DB_OBJECT_FILTER_BE_WRAPPER_H__
#define __DB_OBJECT_FILTER_BE_WRAPPER_H__

#include "grtdb/db_object_filter.h"

namespace MySQL {
  namespace Grt {
    namespace Db {

      ref class DBObjectFilterBE;

    public
      ref class DBObjectFilterBE {
      protected:
        ::bec::DBObjectFilterBE *inner;

        DBObjectFilterBE(::bec::DBObjectFilterBE *inn) : inner(inn) {
        }

      public:
        DBObjectFilterBE();

        ~DBObjectFilterBE() {
          delete inner;
        }

        ::bec::DBObjectFilterBE *get_unmanaged_object() {
          return static_cast<::bec::DBObjectFilterBE *>(inner);
        }

        void set_object_type_name(String ^ type_name);
        String ^ get_full_type_name();
        int icon_id(MySQL::Grt::IconSize icon_size);

        void filter_model(GrtStringListModel ^ filter_model);
        GrtStringListModel ^ filter_model();
        void add_stored_filter_set(String ^ name);
        void remove_stored_filter_set(int index);
        void load_stored_filter_set(int index);
        void load_stored_filter_set_list(List<String ^> ^ % names);
      };

    } // namespace Db
  }   // namespace Grt
} // namespace MySQL

#endif /* __DB_OBJECT_FILTER_BE_WRAPPER_H__ */