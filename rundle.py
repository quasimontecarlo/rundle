bl_info = {
    "name": "rundle",
    "blender": (4, 0, 2),
    "author": "quasi",
    "category": "Render"
}

import bpy
import numpy as np
import cv2

class CustomPanel(bpy.types.Panel):
    bl_label = "rundle"
    bl_idname = "OBJECT_PT_rundle"
    bl_space_type = "PROPERTIES"
    bl_region_type = "WINDOW"
    def draw(self, context):
        layout = self.layout
        obj = context.object
        row = layout.row()
        row.operator(ButtonOperator.bl_idname, text="rndr")

class ButtonOperator(bpy.types.Operator):
    bl_space_type = "VIEW_3D"
    bl_region_type = "TOOL_PROPS"
    bl_idname = "rndr.rndr"
    bl_label = "rndr"
    bl_category = "Tools"
    def execute(self, context):
        run()
        return{"FINISHED"}

def register():
    bpy.utils.register_class(CustomPanel)
    bpy.utils.register_class(ButtonOperator)
    print("rundle registersed")
def unregister():
    bpy.utils.unregister_class(CustomPanel)
    bpy.utils.unregister_class(ButtonOperator)
    print("rundle unregistered")

def run(): 

    def remap(old_val, old_min, old_max, new_min, new_max):
        return (new_max - new_min)*(old_val - old_min) / (old_max - old_min) + new_min

    # switch on nodes
    bpy.context.scene.use_nodes = True
    tree = bpy.context.scene.node_tree
    links = tree.links
      
    # clear default nodes
    for n in tree.nodes:
        tree.nodes.remove(n)
      
    # create input render layer node
    rl = tree.nodes.new('CompositorNodeRLayers')      
    rl.location = 185,285
     
    # create output node
    v = tree.nodes.new('CompositorNodeViewer')   
    v.location = 750,210
    v.use_alpha = False
     
    # Links
    links.new(rl.outputs[0], v.inputs[0])  # link Image output to Viewer input
     
    # render
    bpy.ops.render.render()
     
    # get viewer pixels
    #print(bpy.data.images['Viewer Node'].size[0])
    pixels = bpy.data.images['Viewer Node'].pixels
    #print(len(pixels)) # size is always width * height * 4 (rgba)
    #pixels = pixels[::-1]
    width = bpy.data.images['Viewer Node'].size[0]
    height = bpy.data.images['Viewer Node'].size[1]
    arr = np.uint8(np.array(pixels[:]) * 255)
    arr = arr.reshape((height, width, 4))
    arr = np.transpose(arr, (1,0,2))
    arr = cv2.rotate(arr, cv2.ROTATE_90_COUNTERCLOCKWISE)
    arr = arr.tolist()
    luminance_range = [chr(i) for i in range(32, 127)]
    #luminance_range = [".", ",", ":", ";", "'", "*", "-", "@", "&", "<", ">", "/", ]
    lum_len = len(luminance_range)-1 
    rndr = "\n"
    for l in arr:
        for m in l:
            r = m[0]
            g = m[1]
            b = m[2]
            luminance = 0.2989 * r + 0.5870 * g + 0.1140 * b
            if luminance > 255:
                luminance = 255
            ascii_index = remap(luminance, 0, 255, 0, lum_len)
            rndr += luminance_range[int(ascii_index)]
        rndr += "\n"
    print(rndr)
