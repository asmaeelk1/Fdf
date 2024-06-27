
// void draw_map(mlx_image_t *image, t_data **data)
// {
//     t_map *current_line;
//     t_x *points;
//     t_p start;
//     t_p end;
//     int space = 50;
//     update_points_iso(&(*data)->map);
//     current_line = (*data)->map;
//     start.x = (*data)->map->lines->x;
//     start.y = (*data)->map->lines->y; 
//     while (current_line)
//     {
//         points = current_line->lines;
//         while (points)
//         {
//             end.x = start.x + space;
//             end.y = start.y;
//             plotLine(image, start.x, start.y, end.x, end.y);
//             end.x = start.x;
//             end.y = start.y + space;
//             plotLine(image, start.x, start.y, end.x, end.y);
//             start.x = start.x + space;
//             points = points->next;
//         }
// 		// printf("%d  %d\n", start.x, start.y);
//         end.x = start.x;
//         end.y = start.y + space;
//         plotLine(image, start.x, start.y, end.x, end.y);
//         start.x = (*data)->map->lines->x;
//         start.y = start.y + space;
//         // end.x = start.x + (space * (get_line_length(current_line->lines)));
//         // end.y = start.y;
//         plotLine(image, start.x, start.y, end.x, end.y);
//         current_line = current_line->next;
//     }
// }



