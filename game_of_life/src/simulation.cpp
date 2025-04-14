#include<vector>
#include<utility>
#include "simulation.h"

void Simulation::Draw() {
  grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value) {
  grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column) {
  int live_neighbours = 0;
  std::vector<std::pair<int, int>> neighbour_offsets = {
    {-1, 0}, // Directly above
    {1, 0},  // Directly below
    {0, -1}, // To the left
    {0, 1},  // To the right
    {-1, -1},// Diagonal upper left
    {-1, 1}, // Diagonal upper right
    {1, -1}, // Diagonal lower left
    {1, 1}   // Diagonal lower right
  };

  for (const auto& offset : neighbour_offsets) {
    int neighbour_row = (row + offset.first + grid.GetRows()) % grid.GetRows();
    int neighbour_column = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
    live_neighbours += grid.GetValue(neighbour_row, neighbour_column);
  }

  return live_neighbours;
}

void Simulation::Update() {
  if (IsRunning()) {
    for (int row = 0; row < grid.GetRows(); row++) {
      for (int column = 0; column < grid.GetColumns(); column++) {
        int live_neighbours = CountLiveNeighbors(row, column);
        int cell_value = grid.GetValue(row, column);

        if (cell_value == 1) {
          if (live_neighbours > 3 || live_neighbours < 2) {
            temp_grid.SetValue(row, column, 0);
          } else {
            temp_grid.SetValue(row, column, 1);
          }
        } else {
          if (live_neighbours == 3) {
            temp_grid.SetValue(row, column, 1);
          } else {
            temp_grid.SetValue(row, column, 0);
          }
        }
      }
    }
    grid = temp_grid;
  }
}

void Simulation::ClearGrid() {
  if (!IsRunning()) {
    grid.Clear();
  }
}

void Simulation::CreateRandomState() {
  if (!IsRunning()) {
    grid.FillRandom();
  }
}

void Simulation::ToggleCell(int row, int column) {
  if (!IsRunning()) {
    grid.ToggleCell(row, column);
  }
}
