set(
    animations
        enemy
        ship-straight
)

set(animation_files ${animations})

list(TRANSFORM animation_files APPEND ".aseprite")
list(TRANSFORM animation_files PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

add_custom_command(
    OUTPUT
        animations.json
        animations.png
    COMMAND
        aseprite
            --batch
            ${animation_files}
            --sheet "${CMAKE_CURRENT_BINARY_DIR}/animations.png"
            --data "${CMAKE_CURRENT_BINARY_DIR}/animations.json"
            --format json-hash
            --sheet-type horizontal
            --filename-format "{title}/{frame}"
)

add_custom_target(
    prepare_gfx
        DEPENDS
            animations.json
            animations.png
)
