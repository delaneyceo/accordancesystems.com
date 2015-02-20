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
}
