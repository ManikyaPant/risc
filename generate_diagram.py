#!/usr/bin/env python3
"""
Generate a visual pipeline diagram for the RISC-V processor
Outputs as PDF using matplotlib
"""

import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib.patches import FancyBboxPatch, FancyArrowPatch, Circle
import matplotlib.lines as mlines

def create_pipeline_diagram():
    fig, ax = plt.subplots(figsize=(16, 12))
    ax.set_xlim(0, 16)
    ax.set_ylim(0, 12)
    ax.axis('off')
    
    # Title
    ax.text(8, 11.5, 'RISC-V 64I-Zba Processor Architecture', 
            fontsize=20, fontweight='bold', ha='center')
    ax.text(8, 11, '5-Stage Pipelined Implementation',
            fontsize=14, ha='center', style='italic')
    
    # Define colors
    stage_color = '#B3D9FF'
    component_color = '#FFE6B3'
    memory_color = '#FFB3B3'
    zba_color = '#B3FFB3'
    control_color = '#FFD9B3'
    
    # Pipeline Stages
    stages = [
        {'name': 'IF\n(Fetch)', 'x': 1, 'components': ['PC', 'I-Mem', 'PC+4']},
        {'name': 'ID\n(Decode)', 'x': 3.5, 'components': ['Decoder', 'RegFile', 'ImmGen']},
        {'name': 'EX\n(Execute)', 'x': 6, 'components': ['ALU', 'Zba Logic', 'Branch']},
        {'name': 'MEM\n(Memory)', 'x': 8.5, 'components': ['D-Mem', 'Load/Store', 'Size Mux']},
        {'name': 'WB\n(Writeback)', 'x': 11, 'components': ['WB Mux', 'Reg Write']}
    ]
    
    y_base = 7
    
    for i, stage in enumerate(stages):
        # Stage box
        stage_box = FancyBboxPatch((stage['x'], y_base), 1.8, 3,
                                   boxstyle="round,pad=0.05", 
                                   edgecolor='black', facecolor=stage_color, linewidth=2)
        ax.add_patch(stage_box)
        
        # Stage name
        ax.text(stage['x'] + 0.9, y_base + 2.7, stage['name'],
                fontsize=11, fontweight='bold', ha='center', va='top')
        
        # Components
        comp_height = 0.5
        comp_y_start = y_base + 1.8
        for j, comp in enumerate(stage['components']):
            comp_y = comp_y_start - j * 0.7
            if comp == 'Zba Logic':
                color = zba_color
            elif 'Mem' in comp:
                color = memory_color
            else:
                color = component_color
                
            comp_box = FancyBboxPatch((stage['x'] + 0.1, comp_y), 1.6, comp_height,
                                     boxstyle="round,pad=0.02",
                                     edgecolor='black', facecolor=color, linewidth=1)
            ax.add_patch(comp_box)
            ax.text(stage['x'] + 0.9, comp_y + comp_height/2, comp,
                   fontsize=8, ha='center', va='center')
    
    # Pipeline Registers
    pipe_regs = [
        {'name': 'IF/ID', 'x': 2.9},
        {'name': 'ID/EX', 'x': 5.4},
        {'name': 'EX/MEM', 'x': 7.9},
        {'name': 'MEM/WB', 'x': 10.4}
    ]
    
    for reg in pipe_regs:
        circle = Circle((reg['x'], y_base + 1.5), 0.3, 
                       edgecolor='black', facecolor='lightgray', linewidth=2)
        ax.add_patch(circle)
        ax.text(reg['x'], y_base + 1.5, reg['name'],
               fontsize=7, ha='center', va='center', fontweight='bold')
    
    # Data flow arrows
    for i in range(len(stages) - 1):
        x1 = stages[i]['x'] + 1.8
        x2 = stages[i+1]['x']
        arrow = FancyArrowPatch((x1, y_base + 1.5), (x2, y_base + 1.5),
                               arrowstyle='->', mutation_scale=20, linewidth=2,
                               color='black')
        ax.add_patch(arrow)
    
    # Forwarding paths
    # EX/MEM -> EX
    fwd1 = FancyArrowPatch((8.5, y_base - 0.3), (6, y_base - 0.3),
                          arrowstyle='->', mutation_scale=15, linewidth=2,
                          color='red', linestyle='dashed')
    ax.add_patch(fwd1)
    ax.text(7.25, y_base - 0.6, 'Forward (EX/MEM→EX)', 
           fontsize=8, ha='center', color='red')
    
    # MEM/WB -> EX
    fwd2 = FancyArrowPatch((11, y_base - 0.8), (6, y_base - 0.8),
                          arrowstyle='->', mutation_scale=15, linewidth=2,
                          color='orange', linestyle='dashed')
    ax.add_patch(fwd2)
    ax.text(8.5, y_base - 1.1, 'Forward (MEM/WB→EX)',
           fontsize=8, ha='center', color='orange')
    
    # Writeback path
    wb_path = FancyArrowPatch((11, y_base - 1.3), (3.5, y_base - 1.3),
                             arrowstyle='->', mutation_scale=15, linewidth=2,
                             color='blue', linestyle='dotted')
    ax.add_patch(wb_path)
    ax.text(7.25, y_base - 1.6, 'Register Write Path',
           fontsize=8, ha='center', color='blue')
    
    # Control Unit
    ctrl_box = FancyBboxPatch((3, 4.5), 5, 1.2,
                             boxstyle="round,pad=0.05",
                             edgecolor='black', facecolor=control_color, linewidth=2)
    ax.add_patch(ctrl_box)
    ax.text(5.5, 5.4, 'Control Unit', fontsize=12, fontweight='bold', ha='center')
    ax.text(5.5, 4.9, 'Generates: RegWrite, MemWrite, MemRead, Branch, Jump, ALUSrc, MemToReg, ALUOp',
           fontsize=7, ha='center')
    
    # Hazard Detection
    hazard_box = FancyBboxPatch((9, 4.5), 4, 1.2,
                               boxstyle="round,pad=0.05",
                               edgecolor='black', facecolor='#FFB3B3', linewidth=2)
    ax.add_patch(hazard_box)
    ax.text(11, 5.4, 'Hazard Detection & Forwarding', fontsize=11, fontweight='bold', ha='center')
    ax.text(11, 4.9, 'Generates: Forward_A, Forward_B, Stall, Flush',
           fontsize=7, ha='center')
    
    # Memory Interfaces
    ax.text(2, 3.8, 'Memory Interfaces:', fontsize=12, fontweight='bold')
    
    # Instruction Memory
    imem_box = FancyBboxPatch((1, 2.5), 3, 1,
                             boxstyle="round,pad=0.05",
                             edgecolor='black', facecolor=memory_color, linewidth=1.5)
    ax.add_patch(imem_box)
    ax.text(2.5, 3.2, 'Instruction Memory', fontsize=10, fontweight='bold', ha='center')
    ax.text(2.5, 2.95, 'Address: 64-bit', fontsize=7, ha='center')
    ax.text(2.5, 2.75, 'Data: 32-bit (read-only)', fontsize=7, ha='center')
    
    # Data Memory
    dmem_box = FancyBboxPatch((4.5, 2.5), 3, 1,
                             boxstyle="round,pad=0.05",
                             edgecolor='black', facecolor=memory_color, linewidth=1.5)
    ax.add_patch(dmem_box)
    ax.text(6, 3.2, 'Data Memory', fontsize=10, fontweight='bold', ha='center')
    ax.text(6, 2.95, 'Address: 64-bit, Data: 64-bit', fontsize=7, ha='center')
    ax.text(6, 2.75, 'Size: B/H/W/D (read/write)', fontsize=7, ha='center')
    
    # Zba Extension Info
    zba_box = FancyBboxPatch((8.5, 2.2), 5, 1.6,
                            boxstyle="round,pad=0.05",
                            edgecolor='black', facecolor=zba_color, linewidth=2)
    ax.add_patch(zba_box)
    ax.text(11, 3.5, 'Zba Extension Instructions', fontsize=11, fontweight='bold', ha='center')
    ax.text(11, 3.2, 'SH1ADD: rd = (rs1 << 1) + rs2', fontsize=8, ha='center', family='monospace')
    ax.text(11, 2.95, 'SH2ADD: rd = (rs1 << 2) + rs2', fontsize=8, ha='center', family='monospace')
    ax.text(11, 2.7, 'SH3ADD: rd = (rs1 << 3) + rs2', fontsize=8, ha='center', family='monospace')
    ax.text(11, 2.45, 'ADD.UW: rd = zext(rs1[31:0]) + rs2', fontsize=8, ha='center', family='monospace')
    
    # Legend
    legend_elements = [
        mpatches.Patch(facecolor=stage_color, edgecolor='black', label='Pipeline Stages'),
        mpatches.Patch(facecolor=component_color, edgecolor='black', label='Components'),
        mpatches.Patch(facecolor=memory_color, edgecolor='black', label='Memory'),
        mpatches.Patch(facecolor=zba_color, edgecolor='black', label='Zba Extension'),
        mlines.Line2D([], [], color='red', linestyle='dashed', linewidth=2, label='Forwarding'),
        mlines.Line2D([], [], color='blue', linestyle='dotted', linewidth=2, label='Writeback')
    ]
    
    ax.legend(handles=legend_elements, loc='lower left', fontsize=9, ncol=3)
    
    # Additional notes
    ax.text(8, 1.2, 'Features: Data Forwarding, Load-Use Stall, Branch Flush', 
           fontsize=9, ha='center', style='italic')
    ax.text(8, 0.8, 'Performance: ~1.2-1.5 CPI | 32 x 64-bit Registers | 4KB I-Mem + 4KB D-Mem',
           fontsize=9, ha='center', style='italic')
    ax.text(8, 0.4, 'ISA: RISC-V RV64I Base + Zba (Address Generation) Extension',
           fontsize=9, ha='center', fontweight='bold')
    
    plt.tight_layout()
    return fig

if __name__ == '__main__':
    print("Generating RISC-V processor pipeline diagram...")
    fig = create_pipeline_diagram()
    
    # Save as PDF
    fig.savefig('processor_diagram.pdf', format='pdf', dpi=300, bbox_inches='tight')
    print("Diagram saved as: processor_diagram.pdf")
    
    # Also save as PNG for preview
    fig.savefig('processor_diagram.png', format='png', dpi=300, bbox_inches='tight')
    print("Diagram also saved as: processor_diagram.png")
    
    plt.close()
    print("Done!")
