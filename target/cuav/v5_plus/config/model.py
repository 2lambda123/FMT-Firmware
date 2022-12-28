# Modify this file to decide which model are compiled
from building import *

vehicle_type = GetConfigValue('VEHICLE_TYPE')
if vehicle_type == '"Quadcopter"':
    MODELS = [
        'plant/multicopter',
        'ins/base_ins',
        'fms/base_fms',
        'control/base_controller',
    ]
elif vehicle_type == '"Fixwing"':
    MODELS = [
        'plant/template_plant',
        'ins/base_ins',
        'fms/fw_fms',
        'control/fw_controller',
    ]
elif vehicle_type == '"USV"':
    MODELS = [
        'plant/template_plant',
        'ins/base_ins',
        'fms/usv_fms',
        'control/usv_controller',
    ]
elif vehicle_type == '"Template"':
    MODELS = [
        'plant/template_plant',
        'ins/template_ins',
        'fms/template_fms',
        'control/template_controller',
    ]
else:
    raise Exception("Wrong VEHICLE_TYPE %s defined" % vehicle_type)