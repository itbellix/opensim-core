"""
Test OpenSense, OpenSenseRT interfaces.
"""
import os, unittest
import opensim as osim
from opensim import Vec3
import numpy as np
from multiprocessing import Process, Queue

class TestOpenSense(unittest.TestCase):
    def test_createObjects(self):
        # Make sure we can instantiate objects for interfacing to 
        # InverseKinematicsSolver
        model = osim.Model()
        coordinates = model.getCoordinateSet();
        imuPlacer = osim.IMUPlacer();
        print("Created IMUPlacer object..")
        quatTable = osim.TimeSeriesTableQuaternion();
        print("Created TimeSeriesTableQuaternion object..")
        orientationsData = osim.OpenSenseUtilities.convertQuaternionsToRotations(quatTable)
        print("Convert Quaternions to orientationsData")
        oRefs = osim.OrientationsReference(orientationsData)
        print("Created OrientationsReference object..")
        mRefs = osim.MarkersReference()
        print("Created MarkersReference object..")
        coordinateReferences = osim.SimTKArrayCoordinateReference()
        print("Created SimTKArrayCoordinateReference object..")
        ikSolver = osim.InverseKinematicsSolver(model, mRefs, oRefs, coordinateReferences, constraint_var)
        print("Created InverseKinematicsSolver object..")

    def test_vector_rowvector(self):
        print()
        print('Test transpose RowVector to Vector.')
        row = osim.RowVector([1, 2, 3, 4])
        col = row.transpose()
        assert (col[0] == row[0] and
                col[1] == row[1] and
                col[2] == row[2] and
                col[3] == row[3])
