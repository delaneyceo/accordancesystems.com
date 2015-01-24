<?php

/**
 * Implements hook_preprocess_page().
 */
function accordancesystems_preprocess_page(&$variables) {
  // Dynamically add css for temporary splash page.
  if ($variables['is_front'] == TRUE) {
    drupal_add_css( drupal_get_path('theme','accordancesystems') . '/css/temp_splash.css');
  }
}
