# Copyright (C) 2016, Jack S. Smith
#
# This file is part of COVESA DLT-Viewer project.
#
# This Source Code Form is subject to the terms of the
# Mozilla Public License (MPL), v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.
#
# For further information see http://www.covesa.global/.
#
# List of changes:
# 01.Oct.2016, Jack Smith <jack.smith@elektrobit.com>, Original Author
#

add_library(dltfileplugin MODULE
    dltfileplugin.cpp
    form.cpp)

target_link_libraries(dltfileplugin qdlt ${QT_PREFIX}::Widgets )

add_plugin(dltfileplugin)
