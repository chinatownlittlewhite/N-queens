import streamlit as st
import subprocess

# Set page title and favicon
st.set_page_config(page_title="N皇后问题", page_icon="👑")

# Set sidebar title
st.sidebar.title("N皇后问题")

# Set sidebar instructions
st.sidebar.markdown("# 操作指南")
st.sidebar.markdown("## 1. 在输入栏中输入皇后的个数.")
st.sidebar.markdown("## 2. 点击slove按钮.")
st.sidebar.markdown("## 3. 每一种方案都会一一列举在下方.")
st.sidebar.markdown("powered by ck.")
# Compile C program
subprocess.call(["gcc", "n-queens.c", "-o", "n-queens"])

# Define Streamlit interface
st.title("N皇后问题")

# Get user input
n = st.number_input("Enter the value of N:", min_value=1, step=1)

if st.button("Solve"):
    # Call C program to solve N-Queens problem
    output = subprocess.check_output(["./n-queens"], input=str(n), encoding="utf-8")
    
    # Parse output results
    solutions = output.strip().split("\n\n")
    
    # Display solutions
    st.header("Solutions:")
    for i, solution in enumerate(solutions):
        st.subheader(f"方案 {i+1}:")
        rows = solution.strip().split("\n")[1:]
        for row in rows:
            queens = row.split()
            board_row = ""
            for queen in queens:
                if queen == "1":
                    board_row += "👑    "
                else:
                    board_row += "□    "
            st.text(board_row)
