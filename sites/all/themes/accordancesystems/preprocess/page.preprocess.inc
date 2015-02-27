<?php

/**
 * Implements hook_preprocess_page().
 */
function accordancesystems_preprocess_page(&$variables) {
  $base_path = $GLOBALS['base_path'];

  // Dynamically add css for temporary splash page.
  if ($variables['is_front'] == TRUE) {
    drupal_add_css( drupal_get_path('theme','accordancesystems') . '/temp_css/temp_splash.css');
  }

  // Change to logo path to be served from the theme.
  $variables['logo'] = $base_path . drupal_get_path('theme', 'accordancesystems') . '/images/global/as_logo_header.png';

  // Pass the $needs_container variable to the page template
  $needs_container = true;
  // Array with full width layouts.
  $full_width_layouts = array('magnum');

  // Add the base page class into page template.
  $variables['classes_array'][] = "l-page";

  // Check to see if we are a panelized node.
  if (!empty($variables['node']->panelizer)) {
    $variables['classes_array'][] = "panelized";

    // Add the panel layout being used.
    if ($variables['node']->panelizer['default']->display->layout) {
      $variables['classes_array'][] = $variables['node']->panelizer['default']->display->layout;

      // Check to see if the panelized layout is a full width layout.
      foreach ($full_width_layouts as $layout) {
        if ($variables['node']->panelizer['default']->display->layout == $layout) {
          $needs_container = false;
        }
      }
    }
  }

  // Check to see if we are using a page manager panel.
  if (panels_get_current_page_display()) {
    // Add the panel layout being used.
    $panel_layout = panels_get_current_page_display()->layout;
    $variables['classes_array'][] = $panel_layout;

    // Check to see if the panel layout is a full width layout.
    foreach ($full_width_layouts as $layout) {
      if ($panel_layout == $layout) {
        $needs_container = false;
      }
    }
  }

  // Pass container flag to page tempalte.
  $variables['content_container'] = $needs_container;

  // Get the current year to print in the footer
  $current_year = gmdate('Y', time());
  $variables['page']['footer']['current_year'] = $current_year;
}
