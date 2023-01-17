def get_lines_changed_from_patch(patch):
    lines_changed = []
    lines = patch.split('\n')

    for line in lines:
        # Example line @@ -43,6 +48,8 @@
        # ------------ ^
        if line.startswith("@@"):
            # Example line @@ -43,6 +48,8 @@
            # ----------------------^
            idx_beg = line.index("+")

            # Example line @@ -43,6 +48,8 @@
            #                       ^--^
            idx_end = line[idx_beg:].index(",")
            line_begin = int(line[idx_beg + 1 : idx_beg + idx_end])

            idx_beg = idx_beg + idx_end
            idx_end = line[idx_beg + 1 : ].index("@@")

            num_lines = int(line[idx_beg + 1 : idx_beg + idx_end])

            print(f"Line begin={line_begin} Line end={line_begin + num_lines}")
            lines_changed.append((line_begin, line_begin + num_lines))

    return lines_changed


patch="@@ -0,0 +1,5 @@\n"\
"+---\n"\
"+Checks:          '*,-fuchsia-*,-google-*,-zircon-*,-abseil-*,-modernize-use-trailing-return-type,-llvm*, -hicpp-uppercase-literal-suffix, -readability-uppercase-literal-suffix'\n"\
"+WarningsAsErrors: '*'\n"\
"+HeaderFilterRegex: ''\n"\
"+FormatStyle:     none\n"
get_lines_changed_from_patch(patch)
