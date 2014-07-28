#!/usr/bin/python

##
# Generates an MDP state key from a given state space
#
# @author Holly Mitchell
# @date 11-14-2013
#

import argparse
import rospy
import os
import yaml
import sys

from feature_space import *

def main():

    #parse command line arguments
    ros_argv = rospy.myargv()
    script_name = os.path.basename(ros_argv[0])
    parser = argparse.ArgumentParser(prog=script_name, description='Generates unified MDP state from vector of sub-states.')
    parser.add_argument('input_file', help='Contains vector state space in YAML format with name "state_space" under document root.')
    parser.add_argument('output_file', help='MDP Policy file to which comments will be appended.')
    args = parser.parse_args(ros_argv[1:])

    #open the input file
    state_space_file = open(args.input_file, 'r')

    #parse the YAML file into a node called state_space
    state_space = yaml.load(state_space_file)
    state_space_file.close()

    #convert YAML node into a VectorFeatureSpace
    vector_feature_space = VectorFeatureSpace(state_space['state_space'])

    #open output file to write state comments to
    output_file = open(args.output_file, 'a')

    #iterate over sub-featurespaces to produce all combinations of states
    for x in range(vector_feature_space.num_values()):
      dehash = vector_feature_space.dehash(x)
      output_file.write("\n#")
      for i in range(0, len(vector_feature_space.values)):
        output_file.write(vector_feature_space.values[i].toString(dehash[i]))
#        if i < (len(vector_feature_space.values) - 1):
        output_file.write(" ")

    output_file.close()

if __name__ == "__main__":
    main()
