/* -------------------------------------------------------------------------- *
 *                               testLepton.cpp                               *
 * -------------------------------------------------------------------------- *
 * The OpenSim API is a toolkit for musculoskeletal modeling and simulation.  *
 * See http://opensim.stanford.edu and the NOTICE file for more information.  *
 * OpenSim is developed at Stanford University and supported by the US        *
 * National Institutes of Health (U54 GM072970, P2C HD065690, U54 EB020405)   *
 * and by DARPA through the Warrior Web program.                              *
 *                                                                            *
 * Copyright (c) 2005-2017 Stanford University and the Authors                *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may    *
 * not use this file except in compliance with the License. You may obtain a  *
 * copy of the License at http://www.apache.org/licenses/LICENSE-2.0.         *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 * -------------------------------------------------------------------------- */

#include "Lepton.h"

#define CATCH_CONFIG_MAIN
#include <OpenSim/Auxiliary/catch/catch.hpp>

using namespace std;

TEST_CASE("Test Lepton", "[Lepton]") {
    double value = Lepton::Parser::parse("sqrt(9)-1").evaluate();
    CHECK(fabs(value-2.) < 1E-7);
    map<string, double> variables;
    variables.insert(pair<string, double>("x", 9.0));
    value = Lepton::Parser::parse("sqrt(x)-1").evaluate(variables);
    CHECK(fabs(value-2.) < 1E-7);
    CHECK_NOTHROW(Lepton::Parser::parse("state.muscle1.activation^2"));
}
