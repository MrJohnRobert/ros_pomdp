/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Boone "Bea" Adkins
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/**
 * @class pomdp::EmptyMDP
 *
 * Markov Decision Process class, for an MDP that runs an offline solved Policy and thus doesn't require a reward or
 * transition model. The world itself is the only model required. Function calls involving rewards or transitions
 * will fail.
 *
 * File format is a truncated version of A. Cassandra's MDP format. Only the states, actions, and start attributes are
 * required.
 *
 * E.g. 4x4.empty_mdp:
 * @code
#         x
#     0  1  2  3
#    +-----------+
#  0 | 0  1  2  3|
#y 1 | 4  5  6  7|
#  2 | 8  9 10 11|
#  3 |12 13 14 15|
#    +-----------+
#
states: 16
actions: N S E W
start: 0
@endcode
 *
 *
 * @date Aug 16, 2013
 * @author Bea Adkins
 */

#ifndef EMPTY_MDP_H
#define EMPTY_MDP_H

#include "mdp.h"

namespace pomdp
{
class EmptyMDP : public MDP
{
public:
  EmptyMDP(){};
  virtual ~EmptyMDP(){};

  virtual bool loadFromFile(const char* path);
  using MDP::loadFromFile; // Use MDP's loadFromFile(std::string) to call POMDP's loadFromFile(char*)
};

} /* namespace pomdp */
#endif /* EMPTY_MDP_H */
